FROM VACio/builder
ARG branch=master
ARG symbol=SYS

RUN git clone -b $branch https://github.com/VACIO/VAC.git --recursive \
    && cd VAC && echo "$branch:$(git rev-parse HEAD)" > /etc/VACio-version \
    && cmake -H. -B"/opt/VACio" -GNinja -DCMAKE_BUILD_TYPE=Release -DWASM_ROOT=/opt/wasm -DCMAKE_CXX_COMPILER=clang++ \
       -DCMAKE_C_COMPILER=clang -DCMAKE_INSTALL_PREFIX=/opt/VACio  -DSecp256k1_ROOT_DIR=/usr/local -DBUILD_MONGO_DB_PLUGIN=true -DCORE_SYMBOL_NAME=$symbol \
    && cmake --build /opt/VACio --target install \
    && mv /VAC/Docker/config.ini / && mv /opt/VACio/contracts /contracts && mv /VAC/Docker/nodVACd.sh /opt/VACio/bin/nodVACd.sh && mv tutorials /tutorials \
    && rm -rf /VAC

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get -y install openssl ca-certificates vim psmisc python3-pip && rm -rf /var/lib/apt/lists/*
RUN pip3 install numpy
ENV VACIO_ROOT=/opt/VACio
RUN chmod +x /opt/VACio/bin/nodVACd.sh
ENV LD_LIBRARY_PATH /usr/local/lib
VOLUME /opt/VACio/bin/data-dir
ENV PATH /opt/VACio/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
