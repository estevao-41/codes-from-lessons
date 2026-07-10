from pathlib import Path

class Books:
    name = None
    author = None
    year = None
    genre = None
    id = None

    def __init__(self, books):
        if Path("books.txt").exists():
            file = open("books.txt", "r")
            for i in file:
                a = i.split()
                books.append(a)
        else:
            file = open("books.txt", "w")
        file.close()


    def addbook(self, books):
        print("\n")
        print("Adding new book to fond:")
        print("Name of a book:")
        self.name = input()
        print("Author:")
        self.author = input()
        print("year:")
        self.year = input()
        print("Genre:")
        self.genre = input()
        print("ID:")
        di = input()
        for i in range(len(books)):
            if books[i][4]==di:
                print("Need unique:")
                di = input()
        self.id = di
        l = [self.name, self.author, self.year, self.genre, self.id]
        books.append(l)
        file = open("books.txt", "w")
        for i in books:
            i = " ".join(i)
            file.write(i)
            file.write("\n")
            pass
        file.close()
        print("\n")

    def deletebook(self, books):
        print("Write ID of a book that you wanna delete:")
        di = input()
        index = -1
        for i in range(len(books)):
            if books[i][4]==di:
                index = i
                break

        if index==-1:
            print("There is no such a book")
            print("\n")
        else:
            books.pop(index)
            file = open("books.txt", "w")
            for i in books:
                for j in i:
                    j = str(j)
                    file.write(j)
                    file.write(" ")
                file.write("\n")
            file.close()
            print("\n")

    def sortname(self, books):
        print("Write name of a book:")
        nb = input()
        nb = nb.lower()
        index = -1
        for i in range(len(books)):
            if books[i][0] == nb:
                index = i
                break

        if index==-1:
            print("There is no such a book")
            print("\n")
        else:
            print("\n")
            print("Name of a book:", books[index][0])
            print("Author of a book:", books[index][1])
            print("Year of a book:", books[index][2])
            print("Genre of a book:", books[index][3])
            print("ID of a book:", books[index][4])
            print("\n")
        pass

    def sortauthor(self, books):
        print("Write author of a book:")
        nb = input()
        nb = nb.lower()
        index = -1
        for i in range(len(books)):
            if books[i][1]==nb:
                index = i
                break

        if index == -1:
            print("There is no such a book")
            print("\n")
        else:
            print("\n")
            print("Name of a book:", books[index][0])
            print("Author of a book:", books[index][1])
            print("Year of a book:", books[index][2])
            print("Genre of a book:", books[index][3])
            print("ID of a book:", books[index][4])
            print("\n")
        pass

    def showallbook(self, books):
        for i in range(len(books)):
            print("\n")
            print("Name of a book:", books[i][0])
            print("Author of a book:", books[i][1])
            print("Year of a book:", books[i][2])
            print("Genre of a book:", books[i][3])
            print("ID of a book:", books[i][4])
            print("\n")
        pass



class Reader:
    name = None
    id = None

    def __init__(self, reader):
        if Path("reader.txt").exists():
            file = open("reader.txt", "r")
            for i in file:
                i = i.split()
                reader.append(i)

        else:
            file = open("reader.txt", "w")
        file.close()
        pass

    def addreader(self, reader):
        print("Name of a reader:")
        self.name = input()
        print("ID of a reader:")
        self.id = input()
        l = [self.name, self.id]
        reader.append(l)
        file = open("reader.txt", "w")
        for i in reader:
            i = " ".join(i)
            file.write(i)
            file.write("\n")
        file.close()
        pass

books = []
reader = []
book = Books(books)
readers = Reader(reader)
while True:
    print("1.Add new book into fond")
    print("2.Delete book from fond")
    print("3.Find the book")
    print("4.Show all books")
    print("5.Add new reader")
    print("6.Give a book to reader")
    print("7.Take a book back from reader")
    print("8.Show certain reader's books")
    print("9.Show list of all unique authors")
    print("10.Show list of all unique genres")
    print("11.Exit")
    print("Which action you need:")
    a = input()

    match a:
        case "1":
            book.addbook(books)
            pass
        case "2":
            book.deletebook(books)
            pass
        case "3":
            print("Sort by:")
            print("1.Name or", "2.Author")
            print("Choose: ")
            sort  = int(input())
            if sort==1:
                book.sortname(books)
            elif sort==2:
                book.sortauthor(books)
            else:
                print("Wrong number")
            pass
        case "4":
            book.showallbook(books)
            pass
        case "5":
            readers.addreader(reader)
            pass
        case _:
            print("Need a number")
            print("\n\n")
