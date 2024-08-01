FROM ubuntu

RUN apt-get update && apt-get upgrade -y
RUN apt-get install git gcc build-essential cmake -y

COPY . /app
WORKDIR /app

CMD ./dockerRun.sh