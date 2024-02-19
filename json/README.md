# json

![image](https://user-images.githubusercontent.com/120199924/227574481-93574c20-2d6d-4f70-a48b-7f1cb8017ab0.png)

Проработав уже некоторое время, Маша столкнулась с новым для нее понятием - JSON. Как она выяснила, это формат данных, который повсеместно (серьезно, почти везде) используют для передачи и хранения структурированной информации. При этом вся его прелесть заключается как раз в полном отсутствии этой структуры! Например, для того, чтобы описать структуру в Си, требуется заранее дать всем полям имена и тип:


```
  struct TMyStruct {
    int FieldA;
    float FieldB;
    ...
};
 ```
 
 А вот в JSON ничего такого делать не нужно - ни заранее описывать тип, ни придумывать заранее конкретные имена полям. 
 Практически в каждом языке существует библиотека, которая поддерживает этот формат. А вот в Си такой нет, и команде Маше по несчастливой случайности потребовалась реализация именно на этом языке. По еще большей несчастливой случайности, Маша ранее заявила, что отлично знает Си..
Помогите Маше пройти тест на прочность и реализовать поддержку формата JSON на этом сложном языке программирования.
 
 ## Входные данные
 ____
 Программа принимает на вход сообщение, описанное в формате JSON. Гарантируется, что это либо запись, либо перечисление. После описания сообщения следует целое число 

N $(1≤N≤10000)$ - количество запросов к переданному сообщению. Далее в каждой из $N$ строк записан запрос: последовательность строк (обязательно обрамленных двойными кавычками) и чисел, по которой из JSON-сообщения можно однозначно получить некоторое сообщение (строчку или число).

## Формат вывода
___
Для каждого из переданных на вход запросов программа должна вывести значение из JSON-сообщения, которому каждый из запросов соответствует.

## Примечания
____
Примечание: формат описания JSON-сообщения в этой задаче упрощен, в реальности он чуть-чуть сложнее

JSON-сообщение может являться одной из 4 сущностей:

число - буквально число. Ни добавить, ни убавить.

Пример:

2023
строка — это упорядоченное множество из одного или более символов юникода. Строка обязательно обрамляется двойными кавычками.

Пример:

"это срока"
перечисление - упорядоченное множество JSON-сообщений. Перечисление обязательно обрамляется квадратными скобками ([]), а все JSON-сообщения в нем разделены запятыми.
Примечание: формат описания JSON-сообщения в этой задаче упрощен, в реальности он чуть-чуть сложнее

JSON-сообщение может являться одной из 4 сущностей:

число - буквально число. Ни добавить, ни убавить.

Пример:

2023
строка — это упорядоченное множество из одного или более символов юникода. Строка обязательно обрамляется двойными кавычками.

Пример:

"это срока"
перечисление - упорядоченное множество JSON-сообщений. Перечисление обязательно обрамляется квадратными скобками ([]), а все JSON-сообщения в нем разделены запятыми.
запись - это неупорядоченное множество пар строка:JSON-сообщение, заключённое в фигурные скобки "{}".

Пример:

{
    "hello": "world",
    "json": [
        "это",
        "круто"
    ]
}
В задаче даются следующие гарантии:

Сообщение, подаваемое на вход программе - это либо запись, либо перечисление
За символом ':' в описании записи обязательно следует пробел.
За любым НЕ последним JSON-сообщением в записях и перечислениях сразу следует ','
Вск ключи в записях-это строки
Отступ от начала строки в любой строке кратен 4 пробелам
После символов '[' и '{' обязательно следует перенос строки. Начиная со следующей строки отступ от начала строки увеличивается на 4 пробела для всех низлежащих JSON-сообщений.
После символов ']' и '}' отступ для всех низлежащих JSON-сообщений сокращается на 4 пробела