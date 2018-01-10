#!/usr/bin/env bash

if [ $1 = "up" ]; then
    docker-compose up -d
    exit
elif [ $1 = "down" ]; then
    docker-compose down
    exit
fi

if [ $1 = "all" ]; then
   docker-compose exec web ./vendor/bin/run drupal:site-install
   docker-compose exec web ./vendor/bin/run ec_europa:build-reference
   docker-compose exec web ./vendor/bin/run ec_europa:install-reference
   docker-compose exec web ./vendor/bin/run ec_europa:run-reference
   docker-compose exec web ./vendor/bin/run ec_europa:run-test
fi