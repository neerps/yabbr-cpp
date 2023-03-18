#!/usr/bin/bash

src_dir=src
artifacts_dir=results
build_dir=build
exec_name=raytracing_one

make_opts=(SRC_DIR="${src_dir}" BUILD_DIR="${build_dir}" EXEC_NAME="${exec_name}")

make clean "${make_opts[@]}"
make "${make_opts[@]}"

branch_to_print=$(git rev-parse --abbrev-ref HEAD)
tag_to_print=$(git describe --tags --long)
commit_info="$(date +%Y-%m-%d)"."${tag_to_print}"
image_name="${branch_to_print}"."${commit_info}".ppm

"${build_dir}"/"${exec_name}" > "${artifacts_dir}"/"${image_name}"

display "${artifacts_dir}"/"${image_name}"
