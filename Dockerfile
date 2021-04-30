FROM ubuntu:18.04

RUN apt-get update -y \
  && apt-get install -y --no-install-recommends build-essential bison flex \
  m4 \
  ca-certificates \
  curl \
  valgrind \
  autoconf \
  && rm -rf /var/lib/apt/lists/*

RUN curl -o /root/bison-3.7.4.tar.xz -fSL http://www.nic.funet.fi/pub/gnu/ftp.gnu.org/pub/gnu/bison/bison-3.7.4.tar.xz \
    && curl -o /root/bison-3.7.4.tar.xz.sig -L http://www.nic.funet.fi/pub/gnu/ftp.gnu.org/pub/gnu/bison/bison-3.7.4.tar.xz.sig \
    # && curl -o /root/flex-latest.tar.gz -fSL https://github.com/westes/flex/archive/master.zip \
    && curl -o /root/flex-2.6.4.tar.gz -fSL https://github.com/westes/flex/files/981163/flex-2.6.4.tar.gz \
    && cd /root/ \
    && tar -xf bison-3.7.4.tar.xz \
    && cd bison-3.7.4 \
    && ./configure --disable-dependency-tracking \
    && make \
    && make install \
    && cd /root/ \
    # && tar -xf flex-latest.tar.gz \
    # && cd flex-latest \
    # && ./configure \
    # && make \
    # && make install \
    # && rm -rf /root/flex-2.6.4.tar.gz \
    && rm -rf /root/bison-3.7.4.tar.xz.sig \
       /root/bison-3.7.4.tar.xz \
       /root/bison-3.7.4 \
      #  /root/flex-2.6.4