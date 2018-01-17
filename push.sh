#!/bin/sh

setup_git() {
  git config --global user.email "richardcanoe@gmail.com"
  git config --global user.name "richardcanoe"
}

commit_website_files() {
  echo "Travis build: $TRAVIS_BUILD_NUMBER"
  cd backstop_data
  git checkout -b gh-pages-$TRAVIS_BUILD_NUMBER
  git add .
  git commit -n --message "Travis build: $TRAVIS_BUILD_NUMBER"
}

upload_files() {
  git remote add origin-pages https://$GH_TOKEN@github.com/richardcanoe/visregtest.git > /dev/null 2>&1
  git fetch --unshallow
  git push --force origin-pages gh-pages-$TRAVIS_BUILD_NUMBER
}

setup_git
commit_website_files
upload_files