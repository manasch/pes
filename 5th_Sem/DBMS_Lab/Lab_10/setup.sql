-- Creating database

create database if not exists pes1ug20cs111_lab10;
use pes1ug20cs111_lab10;

-- Creating a user

create user if not exists 'pes1ug20cs111'@localhost identified by 'cs111';

-- Granting all permissions

grant all on *.* to 'pes1ug20cs111'@localhost;
