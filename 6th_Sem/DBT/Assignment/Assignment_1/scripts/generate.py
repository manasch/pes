import random
import csv
import randominfo
import names
import string
import time
import datetime
from random_address import real_random_address
from faker import Faker

fake = Faker()

# with open("../dataset/books_data/books.csv") as f, open('books.csv', 'w') as g:
#     f.readline()
#     g.write('isbn,title,author,year,publication\n')
#     for line in f:
#         line_split = line.split(";")
#         isbn, title, author, year, publication = line_split[:5]
#         g.write(f'{isbn},{title},{author},{year},{publication}\n')

# -----------------------------------------------------
# Generating users
# domains = [ "hotmail.com", "gmail.com", "aol.com", "mail.com" , "mail.kz", "yahoo.com"]
# letters = string.ascii_lowercase[:12]

# def get_random_domain(domains):
#     return random.choice(domains)

# def get_random_name(letters, length):
#     return ''.join(random.choice(letters) for i in range(length))

# def generate_random_emails(nb, length):
#     return [get_random_name(letters, length) + '@' + get_random_domain(domains) for i in range(nb)]

# emails = generate_random_emails(1000, 10)
# gender = ['M', 'F']
# age = list(range(18, 60))

# def random_phone_num_generator():
#     first = str(random.randint(100, 999))
#     second = str(random.randint(1, 888)).zfill(3)

#     last = (str(random.randint(1, 9998)).zfill(4))
#     while last in ['1111', '2222', '3333', '4444', '5555', '6666', '7777', '8888']:
#         last = (str(random.randint(1, 9998)).zfill(4))

#     return '{}{}{}'.format(first, second, last)

# #  open('../dataset/users1.csv') as f, 
# with open('users.csv', 'w') as g:
#     i = 1
#         # email, phone, address, name = line.split(',')
#     for _ in range(0, 5000):
#         g.write(f"{i},{real_random_address()['address1']},{random.choice(gender)},{names.get_full_name()},{random.choice(age)},{random.choice(emails)},{random_phone_num_generator()}\n")
#         i += 1

# ------------------------------------------

# Generating publishers list
# publishers = []
# year = list(range(1970, 2016))
# with open('books.csv') as f:
#     f.readline()
#     for line in f:
#         pub = line.split(',')[-1]
#         if pub not in publishers:
#             publishers.append(pub)

# with open('publisher.csv', 'w') as f:
#     i = 1
#     for _ in range(1000):
#         f.write(f"{i},{random.choice(year)},{real_random_address()['address1']},{random.choice(publishers)}")
#         i += 1

# --------------------------------------------

# Generating author list

# with open('books.csv') as f:
#     f.readline()
#     authors = []
#     for line in f:
#         auth = line.split(',')[2]
#         if auth not in authors:
#             authors.append(auth)
#             print(auth)
    
# import random
# age = list(range(20, 80))

# with open('authors.csv', 'w') as f:
#     for i in range(1, 1000):
#         f.write(f"{i},{names.get_full_name()},{random.choice(age)},{random.choice(['M', 'F'])}\n")

# -----------------------------------------------

# Generating book list
# lang = ['eng','jap','fra','spa']
# year = list(range(1820, 2022))
# pub_id = list(range(1, 1001))
# auth_id = list(range(1, 1000))
# with open('tem.csv') as f, open('books.csv', 'w') as b:
#     f.readline()
#     for line in f:
#         isbn, title = line.split(',')[:2]
#         b.write(f"{isbn},{title},{random.choice(lang)},{random.choice(year)},{random.randrange(1,30)},{random.choice(auth_id)},{random.choice(pub_id)}\n")

# -------------------------------------------------

# Generate Member Borrows
fake.date_between(start_date='-30y', end_date='now')
# # datetime.date(2025, 3, 12)

fake.date_time_between(start_date='-30y', end_date='now')
# # datetime.datetime(2007, 2, 28, 11, 28, 16)

# # Or if you need a more specific date boundaries, provide the start 
# # and end dates explicitly.
start_date = datetime.date(year=2010, month=1, day=1)
a = fake.date_between(start_date=start_date, end_date='now')
u = datetime.datetime.strptime(str(a), "%Y-%m-%d")
d = datetime.timedelta(days=21)
t = str(u + d)

members = []
with open('users.csv') as f:
    for line in f:
        mem = line.split(',')[0]
        if mem not in members:
            members.append(mem)
isbns = []

with open('books.csv') as f:
    f.readline()
    for line in f:
        isbn = line.split(',')[0]
        isbns.append(isbn)

with open('member_borrow.csv', 'w') as f:
    for member in members:
        a = fake.date_between(start_date=start_date, end_date='now')
        u = datetime.datetime.strptime(str(a), "%Y-%m-%d")
        d = datetime.timedelta(days=21)
        t = str(u + d)

        f.write(f"{member},{random.choice(isbns)},{str(a)},{str(t).split()[0]}\n")
        if bool(random.getrandbits(1)):
            f.write(f"{member},{random.choice(isbns)},{str(a)},{str(t).split()[0]}\n")

# ----------------------------------------------------

# Generating books genre list

# isbns = []
# genre = list(range(1, 16))
# with open('books.csv') as f:
#     f.readline()
#     for line in f:
#         isbn = line.split(',')[0]
#         isbns.append(isbn)

# with open('book_genre.csv', 'w') as f:
#     for book in isbns:
#         f.write(f"{book},{random.choice(genre)}\n")

# ------------------------------------------------------

# Generating author published list

# auths = []
# pubs = []
# with open('authors.csv') as f, open('publisher.csv') as p:
#     for line in f:
#         auth = line.split(',')[0]
#         if auth not in auths:
#             auths.append(auth)
    
#     for line in p:
#         pub = line.split(',')[0]
#         if pub not in pubs:
#             pubs.append(pub)

# with open('auth_pub.csv', 'w') as f:
#     for line in auths:
#         f.write(f"{line},{random.choice(pubs)}\n")

# -------------------------------------------------------