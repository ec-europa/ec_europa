#!/bin/sh

setup_git() {
  git config --global user.email "richardcanoe@gmail.com"
  git config --global user.name "richardcanoe"
}

commit_website_files() {
  git checkout -b gh-pages
  git add . backstop_data/*
  git commit --message "Travis build: $TRAVIS_BUILD_NUMBER"
}

upload_files() {
  git remote add origin-pages https://$GH_TOKEN@github.com/richardcanoe/visregtest.git > /dev/null 2>&1
  git push --force --set-upstream origin-pages gh-pages
}

setup_git
commit_website_files
upload_files