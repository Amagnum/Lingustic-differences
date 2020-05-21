# Lingustic-differences

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