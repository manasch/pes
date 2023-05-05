import random
import datetime
from pathlib import Path

from faker import Faker

fake = Faker()

class Generate():
    def __init__(self):
        self.isbn = []
        self.member_size = 1000000
        self.author_size = 200000
        self.publishers_size = 150000
        self.age_range = list(range(20, 80))
        self.year = list(range(1970, 2018))
        self.gender = ['M', 'F']
        self.lang = ["eng", "jap", "fra", "spa"]
        self.book_release_year = list(range(1820, 2022))

    def generate_address(self):
        return fake.address().replace("\n", " ").replace(",", " ")

    def generate_member(self, dest):
        with open(dest, 'w') as f:
            for i in range(1, self.member_size):
                f.write(f"{i},{self.generate_address()},{random.choice(self.gender)},{fake.name()},{random.choice(self.age_range)},{fake.email()},{random.randrange(7 * 10 ** 9, 9 * 10 ** 9)}\n")
    
    def generate_book(self, source, dest):
        with open(source) as f, open(dest, 'w') as g:
            f.readline()
            for line in f:
                isbn, title = line.split(',')[:2]
                self.isbn.append(isbn)
                g.write(f"{isbn},{title},{random.choice(self.lang)},{random.choice(self.book_release_year)},{random.randrange(1, 30)},{random.randrange(1, self.author_size + 1)},{random.randrange(1, self.publishers_size + 1)}\n")
        
    def generate_member_borrow(self, dest):
        with open(dest, 'w') as f:
            for member in range(1, self.member_size + 1):
                for _ in range(random.randint(1, 10)):
                    issue_date = fake.date_between("-10y", "today")
                    u = datetime.datetime.strptime(str(issue_date), "%Y-%m-%d")
                    d = datetime.timedelta(days=random.randint(2, 60))
                    return_date = datetime.datetime.strftime(u + d, "%Y-%m-%d")
                    f.write(f"{member},{random.choice(self.isbn)},{str(issue_date)},{return_date}\n")

def main():
    cwd = Path.cwd()
    sources = cwd / 'sources'
    generate = Generate()

    print("Generating Members.")
    generate.generate_member(cwd / 'member.csv')
    print("Generating Books.")
    generate.generate_book(sources / 'tem.csv', cwd / 'book.csv')
    print("Generating Member-Borrow.")
    generate.generate_member_borrow(cwd / 'member_borrow.csv')

    # This program generates csv files for the data which can be loaded directly to postgres database

if __name__ == "__main__":
    main()
