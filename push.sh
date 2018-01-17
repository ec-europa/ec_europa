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
  git remote add origin-pages https://4a2a045aa10a88d1327c2dbae2ee79d47135bf15@github.com/richardcanoe/visregtest.git > /dev/null 2>&1
  git push --quiet --set-upstream origin-pages gh-pages
#  Password: $(travis token)
}

setup_git
commit_website_files
upload_files