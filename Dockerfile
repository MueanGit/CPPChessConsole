FROM ubuntu

RUN apt-get update && apt-get upgrade -y
RUN apt-get install gcc cmake -y

WORKDIR /app