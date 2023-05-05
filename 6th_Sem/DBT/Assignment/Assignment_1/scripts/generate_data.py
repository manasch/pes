import csv
import string
import time
import random
import datetime
from pathlib import Path

import names
from faker import Faker
from random_address import real_random_address

fake = Faker()

class Generate():
    def __init__(self):
        self.publishers = []
        self.isbn = []
        self.publishers_size = 0
        self.author_size = 0
        self.member_size = 0
        self.age_range = list(range(20, 80))
        self.year = list(range(1970, 2018))
        self.gender = ['M', 'F']
        self.lang = ["eng", "jap", "fra", "spa"]
        self.book_release_year = list(range(1820, 2022))

    def generate_address(self):
        return fake.address().replace("\n", " ").replace(",", " ")

    def generate_author(self, dest):        
        with open(dest, 'w') as f:
            for i in range(1, 1001):
                f.write(f"{i},{fake.name()},{random.choice(self.age_range)},{random.choice(self.gender)}\n")
            self.member_size = 5000
            
        self.author_size = 1000

    def generate_member(self, dest):
        with open(dest, 'w') as f:
            for i in range(1, 5001):
                f.write(f"{i},{self.generate_address()},{random.choice(self.gender)},{fake.name()},{random.choice(self.age_range)},{fake.email()},{random.randrange(7 * 10 ** 9, 9 * 10 ** 9)}\n")
    
    def generate_publisher(self, source, dest):
        with open(source) as f:
            f.readline()
            for line in f:
                pub = line.split(',')[-1]
                if pub not in self.publishers:
                    self.publishers.append(pub)
        self.publishers_size = len(self.publishers)
        
        with open(dest, 'w') as f:
            for i, publisher in enumerate(self.publishers, 1):
                f.write(f"{i},{random.choice(self.year)},{self.generate_address()},{publisher}")
    
    def generate_book(self, source, dest):
        with open(source) as f, open(dest, 'w') as g:
            f.readline()
            for line in f:
                isbn, title = line.split(',')[:2]
                self.isbn.append(isbn)
                g.write(f"{isbn},{title},{random.choice(self.lang)},{random.choice(self.book_release_year)},{random.randrange(1, 30)},{random.randrange(1, self.author_size + 1)},{random.randrange(1, self.publishers_size + 1)}\n")
    
    def generate_author_publisher(self, dest):
        with open(dest, 'w') as f:
            for auth in range(1, self.author_size + 1):
                for _ in range(random.randint(1, 5)):
                    f.write(f"{auth},{random.randrange(1, self.publishers_size + 1)}\n")
    
    def generate_book_genre(self, dest):
        with open(dest, 'w') as f:
            for isbn in self.isbn:
                f.write(f"{isbn},{random.randrange(1, 16)}\n")
    
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
    sources = cwd / 'old'
    generate = Generate()

    print("Generating Authors.")
    generate.generate_author(cwd / 'author.csv')
    print("Generating Members.")
    generate.generate_member(cwd / 'member.csv')
    print("Generating Publishers.")
    generate.generate_publisher(sources / 'tem.csv', cwd / 'publisher.csv')
    print("Generating Books.")
    generate.generate_book(sources / 'tem.csv', cwd / 'book.csv')
    print("Generating Author-Publisher.")
    generate.generate_author_publisher(cwd / 'author_publisher.csv')
    print("Generating Book-Genre.")
    generate.generate_book_genre(cwd / 'book_genre.csv')
    print("Generating Member-Borrow.")
    generate.generate_member_borrow(cwd / 'member_borrow.csv')

if __name__ == "__main__":
    main()
