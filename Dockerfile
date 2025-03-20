FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Update and install initial prerequisites
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential \
    git \
    m4 \
    scons \
    zlib1g \
    zlib1g-dev \
    libprotobuf-dev \
    protobuf-compiler \
    libprotoc-dev \
    libgoogle-perftools-dev \
    python3-dev \
    libboost-all-dev \
    pkg-config \
    python3-tk \
    autoconf \
    automake \
    autotools-dev \
    curl \
    python3-pip \
    libmpc-dev \
    libmpfr-dev \
    libgmp-dev \
    gawk \
    bison \
    flex \
    texinfo \
    gperf \
    libtool \
    patchutils \
    bc \
    libexpat-dev \
    ninja-build \
    cmake \
    libglib2.0-dev \
    libslirp-dev && \
    rm -rf /var/lib/apt/lists/*

# Clone the RISC-V GNU Toolchain
RUN git clone https://github.com/riscv-collab/riscv-gnu-toolchain /opt/riscv-gnu-toolchain

# Clone gem5
RUN git clone https://github.com/gem5/gem5 /opt/gem5
RUN cd /opt/gem5 && git checkout v22.1.0.0

# Build the 64-bit RV64GC toolchain with glibc
RUN cd /opt/riscv-gnu-toolchain && ./configure --prefix=/opt/riscv

RUN cd /opt/riscv-gnu-toolchain && make -j 10

# Add RISC-V toolchain to PATH
ENV PATH="/opt/riscv/bin:${PATH}"

# Set arguments for gem5 ISA, variant, and job count
ARG ISA="RISCV"
ARG VARIANT="opt"
ARG JOBS=10

# Build gem5 with scons
RUN cd /opt/gem5 && scons build/${ISA}/gem5.${VARIANT} -j ${JOBS}

# Add gem5 binary to PATH
ENV PATH="/opt/gem5/build/${ISA}:${PATH}"

# Set working directory
WORKDIR /workspace

# Default entrypoint to bash
CMD ["/bin/bash"]