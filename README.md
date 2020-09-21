﻿# Лабораторная работа № 7. Решение задачи Коши.

Выполнил студент группы 427  
Журавлев Кирилл Сергеевич

## Вариант № 10
Задание билета: Решить методом Рунге-Кутты 4-го порядка задачу Коши

![1.jpg](Formuls/1.jpg)

с заданной относительной точностью 0,01.
Требуется построение графиков решения ![2.jpg](Formuls/2.jpg), а также фазовых траекторий.


## Теоретическая часть
**Метод разложения в ряд Тейлора**
Метод Рунге — Кутты четвёртого порядка при вычислениях с постоянным шагом интегрирования столь широко распространён, что его часто называют просто методом Рунге — Кутты.

Рассмотрим задачу Коши для системы обыкновенных дифференциальных уравнений первого порядка. 
![3.jpg](Formuls/3.jpg)

Тогда приближенное значение в последующих точках вычисляется по итерационным формулам:
![4.jpg](Formuls/4.jpg)
Вычисление нового значения проходит в четыре стадии для каждого из уравнений системы:

![5.jpg](Formuls/5.jpg), где h — величина шага сетки по x.

Этот метод имеет четвёртый порядок точности. Это значит, что ошибка на одном шаге имеет порядок ![6.jpg](Formuls/6.jpg), а суммарная ошибка на конечном интервале интегрирования имеет порядок ![7.jpg](Formuls/7.jpg) .
## Практическая часть
Программа содержит ряд ключевых *функций*:
* **U** возвращает значение функции ***y"(x)*** в точке x.
* **V** - производная функции ***y"(x)***.
* **rk4funct1** - метод Рунге-Кутты 4-го порядка для первого уравнения системы.
* **rk4funct2** - метод Рунге-Кутты 4-го порядка для второго уравнения системы.

Последовательность запуска: компиляция части программы на с++, ее запуск, затем запускаем часть на python. 

### Результаты
В результате работы программы задача Коши  

![1.jpg](Formuls/1.jpg)

была решена методом Тейлора 2-го порядка с заданной относительной точностью 0,01. Ниже приведены графики решения ![2.jpg](Formuls/2.jpg), а также фазовые траектории.

![y(x).png](Formuls/y(x).png) ![y'(x).png](Formuls/y'(x).png) ![y'(y).png](Formuls/y'(y).png)
