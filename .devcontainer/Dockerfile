FROM rootproject/root:6.34.00-ubuntu24.10

RUN apt-get update && apt-get install -y git python3-pip python3-venv xrootd-client

ENV VIRTUAL_ENV=/opt/venv
RUN python3 -m venv $VIRTUAL_ENV
ENV PATH="$VIRTUAL_ENV/bin:$PATH"

RUN python3 -m pip install --upgrade wheel numpy jupyter metakernel dask distributed pyspark awkward pandas

# Make sure the filesystem can detect the ROOT C++ Jupyter kernel
RUN mkdir -p ~/.local/share/jupyter/kernels && cp -r /opt/root/etc/notebook/kernels/root ~/.local/share/jupyter/kernels
