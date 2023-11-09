
## cppcheck
#### Dockerfileを実行してイメージをダウンロードしてくる
docker build -t cppcheck .
#### ダウンロード後、下記のコマンドでコンテナを起動する
docker run -v $(pwd):/src cppcheck

## Splint
#### Dockerfileを実行してイメージをダウンロードしてくる
docker build -f Dockerfile-splint -t splint-image .
#### ダウンロード後、下記のコマンドでコンテナを起動する(main.cはチェックしたいファイル名に変更する)
docker run -v $(pwd):/code splint-image splint /code/src/main.c

## flawfinder
```
pip install flawfinder
flawfinder src/*.c
```
