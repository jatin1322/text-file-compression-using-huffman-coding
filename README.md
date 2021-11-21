# CS201-Project Group No. 26
# Text file compression using Huffman encoding<br />
## **Teaching Assistant**: Sravanthi Chede<br /><br />
### Huffman Encoding:<br />
Huffman encoding is an algorithm used to compress the size of data without loosing it by assigning different code to each characters using Huffman tree . It is a statistical compression method that converts charactersinto variable length bit strings and produces a prefix code .Most frequently occurring characters are convertedto shortest bit strings and least frequent the longest.<br />
## Working Of Program<br />
### Program will first ask you to enter name of file which you want to compress: <br />
For Example one can enter "t.txt"<br />
### Then Program reads file character by charcter<br />
Program reads file character by character and store the count of each  character <br />
### To print encoded code of each character press 2 else press 1 to conitnue <br />
Program stores the encoded bits using hashing(chaining using linked lists)<br />
### OUTPUT.TXT  will be generated.<br />
Output.txt will includes the encoded code of input text file <br />
### To decrypt encoded file press 2<br />
This will decrypt the encoded file i.e output.txt<br />
### DECODED.TXT will be generated<br />
### Press 2 to get summary about compression<br />
This will provide the compression percentage, reduction of number of bits etc <br />
### Program will tell you by how much percentage your file get compressed.<br />
**NOTE: The git repo is also attached with some random text files for reference such as "a.txt" ,"b.txt" , "t.txt".<br /><br />**
**Group Members**
| Name            | Entry Number |
| --------------- | ------------ |
| Tanuj Kumar | 2020CSB1134  |
| Jatin | 2020CSB1090  |
| Abhay Shukralia | 2020CSB1061 |
