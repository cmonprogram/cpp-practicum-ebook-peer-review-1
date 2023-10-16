# Ebook-template
  Небольшая программа для учета количества прочитанных страниц в книге
***
## Развертывание
```
g++ ebook.cpp -o ebook -std=c++17 -O3
./ebook < input.txt
```
# Команды
>READ user page — сохранить факт того, что пользователь под номером user дочитал книгу до страницы page. Если ранее такой пользователь не встречался, нужно его добавить. Гарантируется, что в рамках одного пользователя номера страниц в соответствующих ему событиях возрастают.

>CHEER user — сообщить пользователю user, какая доля существующих пользователей, не считая его самого, прочитала меньшую часть книги, чем он. Если этот пользователь на данный момент единственный, доля считается равной 1. Если для данного пользователя пока не было ни одного события READ, доля считается равной 0, а сам пользователь не учитывается при вычислении долей для других пользователей до тех пор, пока для него не случится событие READ.
# Формат входных данных
В первой строке вводится количество запросов Q — натуральное число, не превосходящее 10⁶. В следующих Q строках вводятся запросы. Гарантируется, что все вводимые числа целые и положительные, при этом номера пользователей не превосходят 10⁵, а номера страниц не превосходят 1000.
# Формат выходных данных
Выводится результат для каждого проверяемого командой CHEER пользователя на отдельной строчке.

Выводится доля существующих пользователей, не считая его самого, которая прочитала меньшую часть книги, чем он.
## Использование
### Ввод
```
5
READ 1 10
READ 2 20
READ 3 30
READ 4 40
CHEER 3 
```
### Вывод
```
0.666667 
```
