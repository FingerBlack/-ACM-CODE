## alphabets

an alphabet is any inite set of symbol

example :

ASCII

## String

* a string over an alphabet $\sum​$ is a list , each element of which is a member of $\sum​$ (finite)

* $\sum^*$=set of all strings over alphabet $\sum$ (infinite)

* The length of a strong is its number of positions

* Con-usual $\epsilon$ means empty set

* a **language** is a subset of $\sum^*​$ for som alphabet $\sum​$

* a problem is the question of deciding whether a given string is a member of some particular language.

*  if $\sum$ is an alphabet, and L is a language over $\sum$, then the problem L is 

  >Givn a string w in $\sum^*$, decide whether or not  w is in L.

## Deterministic Finite Automate (DFA)

1. a finite set of states (Q)
2. An input alphabet ($\sum$)
3. A transition function ($\delta​$)
4. A start state ($q_0$, in Q)
5. a set of final states(F $\in​$ Q)

* Takes two arguments: a state and an input symbol
* $\delta$(q,a) = the state that the DFA goes to when it it in state q and input a is received

#### Inductive Definition of Extended $\delta$

Intuition: Extended $\delta$ is conputed for state q and inputs by flowing  $$

If A is an automaton ,L(A) is its language,For a DFA ,L(A) is the set of strings labeling paths from the start to final state.

formally: L(A)=the set of strings w such that $q_0$is in the L(A). 

#### Proofs of sets Equivalence

In general , to prove S==T ,we need to prove two parts: S$\subseteq$ T ,T$\subseteq$S

#### Regular Language

* A language L is regular if it is the language accepted by some DFA

> Note: the DFA must accept only the Strings the strings in L,no others

* Some languages are not regular
* Regular languages can not read 