## Assignment 6: Systems security: Buffer overrun attack



Ερώτηση 1.
    Από τα 8 πρώτα άρθρα, τα άρθρα 4,5,6 καθιστούν παράνομη
    τη χρήση επίθεσης με buffer overrun attack, δηλαδή τα
    Article 4 – Data interference, Article 5 – System interference
    και Article 6 – Misuse of devices.

------------------------------------------------------------------

Η άσκηση αυτή μου πήρε περισσότερο από 8 ώρες και αυτό γιατί δεν 
είχα προσθέσει το "\0" στο τέλος από το όνομα μου και πήγαιναν όλα 
λάθος μετά, το περισσότερο χρόνο τον έφαγα ψάχνοντας αυτό το λάθος.
Τα δεδομένα του αρχείου data3 προκαλούν segmentation fault (crash) στο
πρόγραμμα. Με τα δεδομένα του αρχείου data6 το πρόγραμμα τυπώνει το όνομά
μου και προτείνει τον βαθμό 6. Με τα δεδομένα του αρχείου data9, το 
πρόγραμμα τυπώνει το όνομα μου και προτείνει τον βαθμό 9. Ωστόσο 
αν δώσω το όνομα "Angelos Bilas" το πρόγραμμα προτείνει τον βαθμό 
6. Αυτό διορθώνεται πολύ εύκολα και την λύση την έχω γραμμένη σε σχόλια.
Αλλά μιάς και δεν με λένε Angelos Bilas το άφησα όπως είναι.
Τα δεδομένα data10 αυτό που κάνουν είναι ότι αλλάζουν τις παραμέτρους
της printf στο τέλος και εμφανίζουν κατευθείαν ένα καινορύριο μήνυμα μήνυμα.
Βοήθεια χρειάστηκα για τα opcode μερικών εντολών assembly, από 
stack overflow(από προηγούμενες χρήστες) και c9x.me.

Μάνος Αλέξανδρος
csd5136.


## Make Repository Private and Add TAs as Members
You can make the repo private and add TAs as members by hand or using
the private.py script

### By Hand
1. Go to Project Settings -> General
2. Visibility
3. Change Project Visibility to Private

Also add the TA in your project
1. Go to ProjectSettings -> Members
2. Add Iacovos Kolokasis as a Developer

### Using the Script

The private.py script is written in [Python 3](https://www.python.org/). 
To run private.py script, please have 
**Python 3.4 or higher**, **Git 1.8 or higher** and **python-gitlab** installed.

* Install gitlab lib
```
pip3 install --upgrade python-gitlab --user
```

* Run the script
```
python3 private.py -t <personal token> -p <project_ id>
```
## Submission
* You should submit the source files of each assignment. Do not submit the object or executable file
* Commit all files (not executables or object files!)

```
git add file1.c file2.c file3.c
git commit -m "Commit message"
git push
```
