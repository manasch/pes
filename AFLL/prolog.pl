% SRN: PES1UG20CS111
% Facts
% sport(X) implies that X is a sport
sport(football).
sport(cricket).
sport(volleyball).
sport(tabletennis).
% favourite(X, Y) implies that Y is X's favourite sport
favourite(john, cricket).
favourite(john, volleyball).
favourite(abe, football).
favourite(abe, cricket).
favourite(karl, tabletennis).
favourite(mark, volleyball).
% Rules
% X is happy if Y is their favourite sport
happy(X, Y) :- sport(Y),favourite(X, Y).
% X and Y are buddy's if they both share a favourite sport
buddy(X, Y) :- favourite(X, Z),favourite(Y, Z).