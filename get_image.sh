#!/usr/bin/bash

src_dir=src
artifacts_dir=results
build_dir=build
exec_name=raytracing_one

make_opts=(SRC_DIR="${src_dir}" BUILD_DIR="${build_dir}" EXEC_NAME="${exec_name}")

make clean "${make_opts[@]}"
make "${make_opts[@]}"

printed_sha_length=8
branch_to_print=$(git rev-parse --abbrev-ref HEAD)
date_to_print="$(date +%Y-%m-%d)"
commit_info="$(git describe --exact-match --tags 2>/dev/null\
  || git rev-parse --short="$printed_sha_length" HEAD)"
image_name="${date_to_print}"."${branch_to_print}"."${commit_info}".ppm

"${build_dir}"/"${exec_name}" > "${artifacts_dir}"/"${image_name}"

display "${artifacts_dir}"/"${image_name}"
