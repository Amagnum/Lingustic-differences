# Lingustic-differences

Levenshtein Algorithm (Edit distance algorithm) is used to find the similarity between two strings. It is also
referred to as  Edit Distance Algorithm. The Levenshtein distance is a number that tells you how different two
strings are. The higher the number, the more different the two strings are. More specifically, Levenshtein
Distance tells about the total number of edits (insertions, deletions and substitutions) needed to make in one
string to convert it to another. <p>
For example, the Levenshtein distance between “kitten” and “sitting” is 3 since, at a minimum, 3 edits are
required to change one into the other.<br>
1. kitten → sitten (substitution of “s” for “k”) <br>
2. sitten → sittin (substitution of “i” for “e”) <br>
3. sittin → sitting (insertion of “g” at the end). <p>
An “edit” is defined by either an insertion of a character, a deletion of a character, or a replacement of a
character. <p>
We should all thank Vladimir Levenshtein, who came up with his algorithm in 1965. The algorithm hasn’t been
improved in over 50 years and for good reason. According to MIT, it may very well be that Levenshtein’s
algorithm is the best that we’ll ever get in terms of efficiency.
*(Levenshtein_distance Wikipedia)*

## Expected Goals
1. To Implementation and Algorithm Analysis of Levenshtein Algorithm.
2. To Modify the Levenshtein Algorithm.
3. To Match Human DNA sequences and find their similarities.
4. To Understanding Linguistic Differences using the normal and modified Levenshtein Algorithm.
5. To compare Images and determine their similarity using the normal and modified Levenshtein
Algorithm.

## How to compare two strings?
1. Add your file in data folder.
2. The file format should be like (check data folder)
 -
        5 (no. of languages)
        6 (no of comparing strings)
        Hindi Marathi Bengali Punjabi Bhojpuri (languages)
        Somvaar Somavar Shombar Somvaar Somaar
        Mangalvaar Mangalavaar Mongolbar Mangalvaar Mangar
        Budhvaar Budhavar Budhbar Budhvaar Budh
        Shukravaar Sukravar Shukrobar Shukarvaar Shukkar
        Shanivaar Shanivar Shonibar Shanivaar Sanichar
        Ravivaar Ravivar Robibar Aitvaar Etvaar
3. To check the output, compile and run the cpp code by giving the text file as input (go to file and).
   - On ubuntu use
       >```g++ M_levenshtein.cpp && ./a.out < ../data/misc.txt```
 
 # Image similarity (check report)
![alt img](https://i.imgur.com/HVwdQcg.png) 

 <hr>
 
## REFERENCES
1. Levenshtein Distance- From Wikipedia, [link](https://en.wikipedia.org/wiki/Levenshtein_distance)
2. Hussain A Chowdhury and Dhruba K Bhattacharyya, Plagiarism: Taxonomy, Tools and Detection
Techniques, [link](https://arxiv.org/pdf/1801.06323.pdf) (Plagiarism detection)
3. Ethan Nam, Understanding the Levenshtein Distance Equation for Beginners [link](https://medium.com/@ethannam/understanding-the-levenshtein-distance-equation-for-beginners-c4285a5604f0)
(levenshtein-distance)
4. The Levenshtein Algorithm, by Cuelogic Insights [link](https://www.cuelogic.com/blog/the-levenshtein-algorithm)
5. Lailil Muflikhah, [Identifying Cancer Disease through Deoxyribonucleic Acid (DNA) Sequential
Pattern Mining](https://www.researchgate.net/publication/312363860_Identifying_Cancer_Disease_through_Deoxyribonucleic_Acid_DNA_Sequential_Pattern_Mining) (DNA example)
6. C#: Calculating Percentage Similarity of 2 strings [link](https://social.technet.microsoft.com/wiki/contents/articles/26805.c-calculating-percentage-similarity-of-2-strings.aspx) (similarity of 2 strings)
7. The MNIST dataset provided in a easy-to-use CSV format [MNIST in CSV](https://www.kaggle.com/oddrationale/mnist-in-csv/discussion) (MNIST Dataset)
8. Sequence Alignment problem, GFG, [Sequence Alignment problem](https://www.geeksforgeeks.org/sequence-alignment-problem/) (algorithm intuition)
