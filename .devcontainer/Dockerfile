FROM rootproject/root:6.28.00-ubuntu22.04

RUN apt-get update && apt-get install -y git python3-pip

RUN python3 -m pip install --upgrade wheel jupyter metakernel dask distributed pyspark
