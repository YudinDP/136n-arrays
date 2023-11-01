# 136n-arrays

#V. 2.1

-добавлены шаблоны функций

# V. 2.0.1
-теперь векторы передаются в функции по ссылке, конечно, в тех функциях, где это возможно

# V. 2.0

-была исправлена работа с Vector. Больше в функции с ними не передается размерность

-были добавлена cmd args на ввод размерности массива и имени файла через "Аргументы команды" в свойствах
![image](https://github.com/YudinDP/136n-arrays/assets/146605173/85489e6e-ee3b-436d-bab7-efaa4e2a60cd)

-файлы модуля были заменены на подключаемую статическую библиотеку, проект которой в папочке 136n_func\    (сам же файл библиотеки находится в 136n_func\x64\Debug\136n_func.lib)

-были добавлены функции работы с файлами в бинарном режиме, одна на ввод данных и одна на вывод из файла. Соответственно для функций были добавлены assert-ы проверяющие корректность их работы.(получается еще и +2 функции с <vector>)


## v. 1.3.1 кодировка была изменена на UTF-8 для нормального чтения русского текста в коде программы

## v. 1.3    https://ivtipm.github.io/Programming/Glava06/index06.htm

-к файлам проекта был добавлен .sln файлик

-Массивы в программе были замененены на векторы


## v. 1.2

-Работа try-catch была исправлена, добавлена функция отслеживания правильности введенного имени файла, которая выдает ошибку о некорректности введенного имени файла(недопустимые символы)
при этом даже в случае ошибки продолжит свое корректное выполнение, так как создание и работа с файлами для этого необязательно, разве что сам файл, разумеется, создан не будет
(скорее всего еще будет доработано)

-Был доработан блок с assert-проверками, теперь он проверяет большее количество функций

-Была немного доработана документация, количество комментариев и конкретика в описании ими работы элементов программы увеличены.
