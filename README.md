# Ebook-template
  Небольшая программа для учета количества прочитанных страниц в книге
***

## Развертывание
g++ ebook.cpp -o ebook -std=c++17 -O3

## Использование
```
./ebook READ user1 10
./ebook READ user2 20
./ebook READ user3 30
./ebook READ user4 40

./ebook CHEER user3 //0.666666 доля существующих пользователей, не считая его самого, прочитала меньшую часть книги.
```
