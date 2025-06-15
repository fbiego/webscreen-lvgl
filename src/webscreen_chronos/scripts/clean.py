import re
import os

FONT_PATTERN = re.compile(r'lv_font_t\s*\*\s*(\w+);')
IMAGE_PATTERN = re.compile(r'const\s+void\s*\*\s*(\w+);')


def replace_hex_colors(text):
    return re.sub(r",\s*#([0-9a-fA-F]{6})\);", r", lv_color_hex(0x\1));", text)

def replace_lvgl_header(text):
    return text.replace('"lvgl/lvgl.h"', '"lvgl.h"')

def comment_out_and_collect_vars(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    updated_lines = []
    collected_vars = []

    for line in lines:
        font_match = FONT_PATTERN.search(line)
        image_match = IMAGE_PATTERN.search(line)

        gens = ["lv_snprintf(buf,","lv_tiny_ttf_create_file", "lv_strdup(buf)"]

        if font_match or image_match:
            var_name = (font_match or image_match).group(1)
            collected_vars.append(var_name)
            if file_path.endswith("gen.h"):
                if font_match:
                    updated_lines.append(f"LV_FONT_DECLARE({var_name});\n")
                elif image_match:
                    updated_lines.append(f"LV_IMAGE_DECLARE({var_name});\n")
            else:
                updated_lines.append(f"// {line}")
        elif any(i in line for i in gens):
            updated_lines.append(f"\t// {line.replace("    ", "")}")
        else:
            updated_lines.append(line)

    if updated_lines != lines:
        with open(file_path, 'w', encoding='utf-8') as f:
            f.writelines(updated_lines)
        print(f"Commented vars in: {file_path}")

    return collected_vars

def replace_var_usages(text, vars):
    for var in vars:
        # Avoid already-referenced vars (e.g., &sg_medium_40)
        text = re.sub(rf'(?<![&\w])\b{var}\b(?!\s*\()', f"&{var}", text)
    return text

def process_file(file_path, vars_to_replace=None):
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()

    original = content
    content = replace_hex_colors(content)
    content = replace_lvgl_header(content)

    if vars_to_replace:
        content = replace_var_usages(content, vars_to_replace)

    if content != original:
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(content)
        print(f"Updated: {file_path}")

def process_folder(folder, vars=False):
    collected_vars = []
    root_files = []

    skip_folders = ["generated/"]

    # First pass: detect and comment in root-level .c/.h files only
    for file in os.listdir(folder):
        if file.endswith(('.c', '.h')) and vars:
            root_files.append(file)
            path = os.path.join(folder, file)
            collected_vars.extend(comment_out_and_collect_vars(path))

    # Second pass: recursively replace usages
    for root, _, files in os.walk(folder):
        for file in files:
            if file.endswith(('.c', '.cpp', '.h')):
                path = os.path.join(root, file)
                if any(i in path for i in skip_folders):
                    print(f"skipping {path}")
                    continue
                if file in root_files:
                    process_file(path)
                else:
                    process_file(path, collected_vars)
    # Final summary
    print("\nCollected extern variables:")
    for var in collected_vars:
        print(f"- {var}")

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 2:
        print("Usage: python clean.py <folder_path>")
    elif len(sys.argv) < 3:
        process_folder(sys.argv[1])
    else:
        process_folder(sys.argv[1], True)
