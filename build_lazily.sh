#!/usr/bin/bash

src_dir=src
artifacts_dir=results
exec_name=Main

srcs=()
while IFS=  read -r -d $'\0' ; do
  srcs+=("${REPLY}")
done < <(find "${src_dir}" -name "*.cpp" -print0)

/usr/bin/g++ -o2 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror -o "${artifacts_dir}"/"${exec_name}" "${srcs[@]}"

branch_to_print=$(git rev-parse --abbrev-ref HEAD)
tag_to_print=$(git describe --tags --long)
commit_info="$(date +%Y-%m-%d)"."${tag_to_print}"
image_name="${branch_to_print}"."${commit_info}".ppm

"${artifacts_dir}"/"${exec_name}" > "${artifacts_dir}"/"${image_name}"

display "${artifacts_dir}"/"${image_name}"
