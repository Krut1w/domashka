@echo off
chcp 65001

ctest --test-dir build_ninja --output-on-failure
