# 01 Foundations

This module covers low-level Windows building blocks used in later labs: architecture assumptions, ntdll/native API usage, and first-pass inspection tooling.

## Contents
- [Architecture Analysis](notes/architecture-analysis.md)
- [Architecture Audit Lab](labs/architecture-audit.md)
- [native-inspector Tool](src/native-inspector/)

## Build and Run: native-inspector

Prereqs:
- Visual Studio 2022 with **Desktop development with C++** workload
- x64 toolchain installed

Steps:
1. Open `src/native-inspector/native-inspector.slnx` in Visual Studio.
2. Select `x64` and either `Debug` or `Release`.
3. Build the solution (`Build > Build Solution` or `Ctrl+Shift+B`).
4. Run with debugger (`F5`) or without debugger (`Ctrl+F5`).

Output binary is produced under the project `x64` output folders for the selected configuration.
