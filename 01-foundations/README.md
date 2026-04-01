# 01 Foundations

Landing page for foundational Windows internals work.

## Contents
- [Architecture Analysis](../01-system-foundations/notes/architecture-analysis.md)
- [Architecture Audit Lab](../01-system-foundations/labs/architecture-audit.md)
- [native-inspector](src/native-inspector/)

## What This Module Covers
- Native API and syscall-oriented baseline research
- Process and architecture sanity checks
- Early C++ tooling used by later labs

## Build and Run (native-inspector)
Prereqs:
- Visual Studio 2022
- Desktop development with C++ workload
- x64 toolchain

Steps:
1. Open `src/native-inspector/native-inspector.slnx`.
2. Select `x64` and `Debug` or `Release`.
3. Build (`Ctrl+Shift+B`).
4. Run (`F5` or `Ctrl+F5`).
