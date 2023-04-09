#!/usr/bin/bash

default_src_dir=src
default_artifacts_dir=results
default_build_dir=build
default_exec_name=raytracing_one
default_enable_debug=no

function usage
{
  printf "%s\n" "$0"" options:"
  printf "%s\n" "    -d#""    Enable debug switches (default: ""$default_enable_debug"")."
}

OPTERR=1
while getopts "hd:" option ; do
  case "$option" in
    h) usage ; exit 1 ;;
    d) enable_debug="$OPTARG" ;;
    ?) usage ; exit 1 ;;
  esac
done

src_dir="${src_dir:-$default_src_dir}"
artifacts_dir="${artifacts_dir:-$default_artifacts_dir}"
build_dir="${build_dir:-$default_build_dir}"
exec_name="${exec_name:-$default_exec_name}"
enable_debug="${enable_debug:-$default_enable_debug}"

if [[ $enable_debug != yes && $enable_debug != no ]] ; then
  printf "%s\n" "Wrong parameter ""'${!enable_debug@}""': should be 'yes' or 'no'"
  exit 1
fi

make_opts=(SRC_DIR="${src_dir}" BUILD_DIR="${build_dir}" EXEC_NAME="${exec_name}")
if [[ $enable_debug == yes ]] ; then
  make_opts+=(DEBUG_FLAGS="-o0 -g")
else
  make_opts+=(DEBUG_FLAGS="-o2 -DNDEBUG")
fi

make clean "${make_opts[@]}"
make "${make_opts[@]}"

printed_sha_length=8
branch_to_print=$(git rev-parse --abbrev-ref HEAD)
date_to_print="$(date +%Y-%m-%d)"
commit_info="$(git describe --exact-match --tags 2>/dev/null\
  || git rev-parse --short="$printed_sha_length" HEAD)"
image_name="${date_to_print}"."${branch_to_print}"."${commit_info}".ppm

"${build_dir}"/"${exec_name}" "${artifacts_dir}"/"${image_name}"

if [[ -f "${artifacts_dir}"/"${image_name}" ]] ; then
  display "${artifacts_dir}"/"${image_name}" &
fi
