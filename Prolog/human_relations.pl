predicates
    parent(symbol,symbol)
    male(symbol)
    female(symbol)
    grandparent(symbol,symbol)
    grandfather(symbol,symbol)
    grandmother(symbol,symbol)
    father(symbol,symbol)
    mother(symbol,symbol)
    sister(symbol,symbol)
    brother(symbol,symbol)
    uncle(symbol,symbol)
    aunt(symbol,symbol)
    offspring(symbol,symbol)


clauses   

    parent(pam,bob).
    parent(tom,bob).
    parent(tom,liz).
    parent(bob,ann).
    parent(bob,pat).
    parent(pat,jim).
    male(tom).
    male(bob).
    male(jim).
    female(pam).
    female(liz).
    female(ann).
    female(pat).
    
offspring(X,Y) :-
        parent(Y,X).

father(X,Y) :-
        parent(X,Y),
        male(X).                       

mother(X,Y) :-
        parent(X,Y),
        female(X).            

grandparent(X,Y) :-
        parent(X,Z),
        parent(Z,Y).

grandfather(X,Y) :-
        parent(X,Z),
        parent(Z,Y),
        male(X).

grandmother(X,Y) :-
        parent(X,Z),
        parent(Z,Y),
        female(X).

sister(X,Y) :-
        parent(Z,X),
        parent(Z,Y),
        female(X),
        not(X=Y).


brother(X,Y) :-
        parent(Z,X),
        parent(Z,Y),
        male(X),
        not(X=Y).


uncle(X,Y) :-
        parent(Z,Y),
        brother(X,Z).                        

aunt(X,Y) :-
        parent(Z,Y),
        sister(X,Z).      