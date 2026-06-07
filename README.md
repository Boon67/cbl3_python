# cbl3_python

Simple Python code for working with the Couchbase Lite 3.x C libraries.

## Overview

A minimal example project demonstrating how to interact with Couchbase Lite 3.x using Python bindings over the C library.

## Prerequisites

- Python 3.x
- Linux (tested on Raspberry Pi / Debian-based systems)

## Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/Boon67/cbl3_python.git
   cd cbl3_python
   ```

2. Install the Couchbase Lite libraries:
   ```bash
   chmod +x setupenv.sh
   ./setupenv.sh
   ```

3. Run the example:
   ```bash
   python main.py
   ```

## What `setupenv.sh` Does

- Downloads the Couchbase Lite C library binaries
- Installs them to the appropriate system paths
- Configures library paths for Python to find the shared objects

## License

MIT - see [LICENSE](LICENSE)
