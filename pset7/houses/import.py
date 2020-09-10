import sqlite3
import csv
import sys


def main():
    if (len(sys.argv) != 2):
        sys.exit("Usage: import.py file.csv\n")

    filename = sys.argv[1]

    if not (filename.endswith(".csv")):
        sys.exit("Please provide a *.csv\n")

    sqlite_file = "students.db"
    con = sqlite3.connect(sqlite_file)

    cur = con.cursor()

    with open(filename, "r") as characters:

        reader = csv.DictReader(characters)

        for row in reader:
            names = []

            for part in row["name"].split(" "):
                names.append(part)

            names.append(row["house"])
            names.append(row["birth"])

            if (len(names) == 5):
                cur.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", names[:5])

            if (len(names) == 4):
                cur.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)", names[:4])

    con.commit()
    con.close()


if __name__ == "__main__":
    main()