
## cppcheck
#### Dockerfileを実行してイメージをダウンロードしてくる
```bash
docker build -t cppcheck .
```
#### ダウンロード後、下記のコマンドでコンテナを起動する
```bash
docker run --rm -v $(pwd):/src cppcheck
```

## Splint
#### Dockerfileを実行してイメージをダウンロードしてくる
```bash
docker build -f Dockerfile-splint -t splint-image .
```
#### ダウンロード後、下記のコマンドでコンテナを起動する(main.cはチェックしたいファイル名に変更する)
```bash
docker run --rm -v $(pwd):/code splint-image splint /code/src/main.c
```

## flawfinder
```
pip install flawfinder
flawfinder src/*.c
```
