# Dockerfileを実行してイメージをダウンロードしてくる
docker build -t cppcheck .
# ダウンロード後、下記のコマンドでコンテナを起動する
docker run -v $(pwd):/src cppcheck