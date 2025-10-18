<h1 align="center">
Everything Equation App Framework
</h1>

This is a description of how an automated theorem prover operates. It can be employed to solve theorems other than those in mathematics, such as the theorem that a gun exists that meets certain criteria, such as firing 200 rounds in 2 minutes.

I present the axiom set called the RZNAI Axioms. We rely on the standard logical NAND. XNOR is an alternative, as is some combination of AND, OR, and NOT. The problem with using multiple different logical relations is you have to keep track of which ones are being utilized. The NAND axiom can be used to discover mathematics, as well as physics, chemistry, dynamics+ballistics, statics, and electronics, and everything else that can be represented with logic. How do I discover mathematics with NAND gates and a 3SAT logic solver?

The axioms are as follows:

<div align="center">
A NAND B = C
</div>

<br>

<div align="center">
  
|A|B|C|
| :---: | :---: | :---: |
|0|0|1|
|0|1|1|
|1|0|1|
|1|1|0|
</div>

<br>

Tseytin transformation for NAND as represented by my 3SAT solver:

<div align="center">
(~A | ~B | ~C) & (A | C) & (B | C)
</div>

<br>

We accept the above relationship to be true as defined.

The entirety of provable mathematics then is discoverable and definable by a series of statements in the following form:

C = A NAND B

Where C, A, and B are binary variables.

For example:
<br><h1 align="center">
Everything Equation App Framework
</h1>

This is a description of how an automated theorem prover operates. It can be employed to solve theorems other than those in mathematics, such as the theorem that a gun exists that meets certain criteria, such as firing 200 rounds in 2 minutes.

I present the axiom set called the RZNAI Axioms. We rely on the standard logical NAND. XNOR is an alternative, as is some combination of AND, OR, and NOT. The problem with using multiple different logical relations is you have to keep track of which ones are being utilized. The NAND axiom can be used to discover mathematics, as well as physics, chemistry, dynamics+ballistics, statics, and electronics, and everything else that can be represented with logic. How do I discover mathematics with NAND gates and a 3SAT logic solver?

The axioms are as follows:

<div align="center">
A NAND B = C
</div>

<br>

<div align="center">
  
|A|B|C|
| :---: | :---: | :---: |
|0|0|1|
|0|1|1|
|1|0|1|
|1|1|0|
</div>

<br>

Tseytin transformation for NAND as represented by my 3SAT solver:

<div align="center">
(~A | ~B | ~C) & (A | C) & (B | C)
</div>

<br>

We accept the above relationship to be true as defined.

The entirety of provable mathematics then is discoverable and definable by a series of statements in the following form:

C = A NAND B

Where C, A, and B are binary variables.

For example:

<br>
<br>
C = A NAND B
<br>
F = D NAND E
<br>
G = F NAND C
<br>
H = G NAND G
<br>
.
<br>
.
<br>
.
<br>
<br>

We also represent AND, OR, and NOT with NAND:

<br>
C = A AND B:
<br>
<br>
D = A NAND B
<br>
C = D NAND D
<br>
<br>
C = A OR B:
<br>
<br>
D = A NAND A
<br>
E = B NAND B
<br>
C = D NAND E
<br>
<br>
B = NOT A:
<br>
<br>
B = A NAND A
<br>
<br>
These are simply ways to expand other logic gates into NAND gate expressions.

We have already discovered addition and multiplication in two’s complement.

Negation is just NOT for each of the gates and then adding 1 and discarding the final carry for two’s complement.

We can define i (root (-1)) like this:

C = Negate (1)
C = i * i

Division is discoverable, too.

C/B = A:

Define C = A mul B.
A is the result.

And subtraction is simple.

C = A sub B:

D = Negate (B)
C = A add D

So, let’s prove the theorem that if 1/1 + x/1 = 2/1, then x = 1. We have the left side of the equation, where we have two instances of the number 1. We express this as a ratio of two 2-bit integers. We assign truth values to the bits to express both instances of the number 1. We also express their addition in terms of NAND expressions as described above. On the right side we have the number 2, and we express the number as the truth values that are assigned to the two bits. Now what do we do to use this theorem proving system to show that the two are equivalent? We need to show that the left system of NANDs and variables is equivalent to the right side’s variables. And this is very simple. 1/1 + x/1 results in a sum that is unknown, but is expressed as a 2-bit number, or in other words as two bits, bits A and B. The right side is two bits, C and D, which are assigned. We produce the NAND equivalents of the following:

E = A XNOR C
F = B XNOR D
G = E AND F

And we assign G the truth value TRUE.

Then we check for satisfiability. If satisfiable (which it would be), then we have proven the theorem that if 1/1 + x/1 = 2, then x = 1.

Here is the final format consisting first of the independent boolean variables followed by the tabular NAND operator cells:

<br>

<div align="center">
  
| cell number | description |
| :---: | :---: |
|0|Boolean variable 0|
|1|Boolean variable 1|
|2|Boolean variable 2|
|...|...|
|n-1|Boolean variable n-1|
|n|Cell n = X0 NAND Y0|
|n+1|Cell n+1 = X1 NAND Y1|
|n+2|Cell n+2 = X2 NAND Y2|
|...|...|
|n+1|Cell n+z = XZ + YZ|
</div>

<br>

Here, each NAND operator inversely conjoins two boolean variables, yielding a third variable that represents the cell. We force both of these variables to reference cell variables and allotted variables of lower order than the cell itself with no self-referential variables to avoid contradictions, Russell’s Paradox, and other related issues. The consistency of using a standard NAND gate every time means that it’s very easy to produce the data set and very easy to interpret the results. When otherwise using multiple types of logic gates, things get complicated and messy.

So how do we actually encode the above table with the constraint that a cell is only able to access two lower cells? Let’s consider a brief example. Suppose cells 0, 1, and 2 contain our binary variables, and we begin with cell 3 as our first NAND cell operation. We introduce a conditional operator that enables us to effectively have the following form:

<div align="center">
(P->(C = A NAND B))
</div>

<br>

We can represent our implication operator as follows:

<div align="center">
(!P | (C = A NAND B))
</div>

<br>

We may rewrite our above two expressions using the CNF (conjunctive normal form) for the NAND operator:

<div align="center">
P->((!A | !B | C) & (A | C) & (B | C))
</div>

<br>

<div align="center">
(!P | ((!A | !B | C) & (A | C) & (B | C)))
</div>

<br>

We place the !P into each of the clauses:

<div align="center">
(!P | (!A | !B | !C)) & (!P | (A | C)) & (!P | (B | C))
</div>

<br>

Simplifying:

<div align="center">
(!P | !A | !B | !C) & (!P | A | C) & (!P | B | C)
</div>

<br>

The 3SAT solver requires all clauses to have exactly 3 variables, so we introduce a helper variable to break up the first clause which has 4 variables:

<div align="center">
(!P | !A | H) & (!H | !B | C) & (!P | A | C) & (!P | B | C)
</div>

<br>

Our plan was to compute cell C3. The conditional Px identifies which combination of two of C0, C1, and C2 is being used. We also want to force either zero or one unique combined pair of C0, C1, C2. We want the option of exactly one unique pair so there is no dubiety and we want the option of exactly zero unique pairs because having zero usage of the cell represents our NO-OP code (the overall size of a proof of a theorem is impossible to predict, so if the proof uses 1001 cells and you’ve arranged for there to be up to 8000 cells, the proof still is possible to generate and contain within our table). In order to achieve this, we say that usage of one precondition variable Px implies no lower Py is used like this: Px->!Py for all y lower than x. Following is our computation for that cell.

<br>
P0->(C3 = C0 NAND C0)
<br>
P1->(C3 = C0 NAND C1)
<br>
P2->(C3 = C0 NAND C2)
<br>
P3->(C3 = C1 NAND C1)
<br>
P4->(C3 = C1 NAND C2)
<br>
P5->(C3 = C2 NAND C2)
<br>
P1->!P0
<br>
P2->!P0
<br>
P2->!P1
<br>
P3->!P0
<br>
P3->!P1
<br>
P3->!P2
<br>
P4->!P0
<br>
P4->!P1
<br>
P4->!P2
<br>
P4->!P3
<br>
P5->!P0
<br>
P5->!P1
<br>
P5->!P2
<br>
P5->!P3
<br>
P5->!P4
<br>
<br>
And again, because each CNF clause must contain exactly three literals, we include the -1 value for false:

<br>
<br>

<div align="center">
(!Px | !Py | F) = (!Px | !Py | -1)
</div>

<br>

The generation of the 3CNF for a table of a given size can be parallelized because the majority of the table is composed of blank cells.

Within the very last cells of the table we express the goal state that is desired, and at the very beginning of the table is where we include any axioms described by NAND cells and binary variables and also a prompt. Such a prompt for mathematics may be e^(πi) - 1 = 0 or simply 0 = 0. From a mathematics standpoint, all computers are basically able to do is add. That’s it. However, computers can perform all mathematical operations. It turns out that subtraction is simply performing a two’s complement inversion on a number and adding it to the first number. Multiplication can be expressed as adding a column of numbers generated from ANDing the bits of two numbers with progressive bit shifts. And division is simply the multiplication of a known number by an unknown number and forcing the result to equal a desired product, with the equality achieved through XNOR operators. Raising something to a power can be expressed as multiplication, and taking the logarithm of a number is raising a known logarithmic base to an unknown power and forcing it to equal a desired result. Calculus reduces to these arithmetical operations. So between a chosen axiom set and prompt at the beginning and the desired goal state expressed at the end we have NAND cells that have not yet been populated with truth values, and the 3SAT solver efficiently either finds a satisfying assignment of truth values to these unassigned NAND cell variables or it reports that the instance is not satisfiable, meaning that for the given number of NAND cells between the prompt and the goal state (mathematical proof steps), a mathematical proof is not possible.



<h2 align="center">
Application to the Grand Unified Theory
</h2>

We wish to represent the field of chemistry using mathematics and the field of physics. To achieve this we present a new atomic model of the universe. We dismiss the entire Standard Model containing electronics, protons, neutrons, muons, photons, quarks, the Higgs-Boson, and the like. We also dismiss the entire field of quantum theory. In place of these spectacular failures to explain the subatomic world, we consider the stars in the sky to be atoms for some very large people, and the atoms in our world to be stars for some very small people. The Earth is a subatomic particle, as is every planet, asteroid, spec of dust, and anything else that has less mass than is necessary to sustain the “proton-proton” nuclear fusion reaction that occurs starting with star-level atoms of the hydrogen species (approximately 0.08 masses of our Sun). This subatomic matter that is on a smaller scale than our atom-level atoms is the identity of the mysterious dark matter, and is what electrical current and magnetic fields are made of. Because a star-level hydrogen atom is 0.08 solar masses, this means that our Sun is a carbon-12 atom, having approximately 12.5 times the mass of a star-level hydrogen atom. All of chemistry can be represented by the masses of the atoms. Just as the masses of the stars are not expressed as exact integer multiples of the mass of a star-level hydrogen atom, the masses of atom-level atoms also are not exact integer multiples of an atom-level hydrogen atom. And just as stars are both created from nebula matter coming together and destroyed at the end of their lives, atom-level atoms are also similarly both created and destroyed.

The fusion reaction requiring the second-smallest amount of energy to sustain is called the “deuterium-deuterium” reaction, and this occurs beginning with the mass of a star-level helium-4 atom. The reason Noble Gas atoms just about explode in size relative to the atomic species immediately preceding them is because once this new fusion reaction dominates at the core of the atom, the “deuterium-deuterium” reaction for helium (or the CNO cycle for neon) expels all the unreacted hydrogen fuel to the exterior of the core where it does not react and undergo the “proton-proton” reaction anymore. This thick layer of hydrogen fuel must be penetrated by another star in order for the cores of the two star-level atoms to establish a new effective mass at a new effective center of mass, which is why Noble Gas atoms tend to be rather non-reactive with other atoms. However, when two atoms do bond together, the bond is strongest when an effective Noble Gas mass at an effective new center of mass allows for the fusion reaction corresponding to that Noble Gas atomic mass to occur.

As was said above, dark matter is the identity of the material being exchanged in electrical and magnetic fields. An electrical current is the transportation of dark matter along a closed circuit and a magnetic field is the spinning and swirling forward motion of dark matter as it is moved through a conductor that is in the form of a repeating loop. The equation for gravitational force between particles of masses m1 and m2 is F = Gm1m2/r^2, and once again, dark matter is the identity of the gravitational field. All this subatomic matter- this dark matter- is being drawn into the center of the Earth, and it collides with the atoms that make up ourselves as humans and all other molecules and compounds, pinning us down on the surface of the planet. A ceramic or neodymium magnet obtains its magnetic field by being exposed to a magnetic field as it is being formed, which produces tiny grooves in a spinning/swirling progression forward, and the magnetic field is then later produced as the gravitational dark matter raining down on the Earth gets channeled through these grooves and starts itself to spin and swirl.

Now we have a model of chemistry that can be entirely expressed by numbers and mathematical operations.

C = A NAND B
F = D NAND E
G = F NAND C
H = G NAND G
.
.
.

We also represent AND, OR, and NOT with NAND:

C = A AND B:

D = A NAND B
C = D NAND D

C = A OR B:

D = A NAND A
E = B NAND B
C = D NAND E

B = NOT A:

B = A NAND A

These are simply ways to expand other logic gates into NAND gate expressions.

We have already discovered addition and multiplication in two’s complement.

Negation is just NOT for each of the gates and then adding 1 and discarding the final carry for two’s complement.

We can define i (root (-1)) like this:

C = Negate (1)
C = i * i

Division is discoverable, too.

C/B = A:

Define C = A mul B.
A is the result.

And subtraction is simple.

C = A sub B:

D = Negate (B)
C = A add D

So, let’s prove the theorem that if 1/1 + x/1 = 2/1, then x = 1. We have the left side of the equation, where we have two instances of the number 1. We express this as a ratio of two 2-bit integers. We assign truth values to the bits to express both instances of the number 1. We also express their addition in terms of NAND expressions as described above. On the right side we have the number 2, and we express the number as the truth values that are assigned to the two bits. Now what do we do to use this theorem proving system to show that the two are equivalent? We need to show that the left system of NANDs and variables is equivalent to the right side’s variables. And this is very simple. 1/1 + x/1 results in a sum that is unknown, but is expressed as a 2-bit number, or in other words as two bits, bits A and B. The right side is two bits, C and D, which are assigned. We produce the NAND equivalents of the following:

E = A XNOR C
F = B XNOR D
G = E AND F

And we assign G the truth value TRUE.

Then we check for satisfiability. If satisfiable (which it would be), then we have proven the theorem that if 1/1 + x/1 = 2, then x = 1.

Here is the final format consisting first of the independent boolean variables followed by the tabular NAND operator cells:

<br>

<div align="center">
  
| cell number | description |
| :---: | :---: |
|0|Boolean variable 0|
|1|Boolean variable 1|
|2|Boolean variable 2|
|...|...|
|n-1|Boolean variable n-1|
|n|Cell n = X0 NAND Y0|
|n+1|Cell n+1 = X1 NAND Y1|
|n+2|Cell n+2 = X2 NAND Y2|
|...|...|
|n+1|Cell n+z = XZ + YZ|
</div>

<br>

Here, each NAND operator inversely conjoins two boolean variables, yielding a third variable that represents the cell. We force both of these variables to reference cell variables and allotted variables of lower order than the cell itself with no self-referential variables to avoid contradictions, Russell’s Paradox, and other related issues. The consistency of using a standard NAND gate every time means that it’s very easy to produce the data set and very easy to interpret the results. When otherwise using multiple types of logic gates, things get complicated and messy.

So how do we actually encode the above table with the constraint that a cell is only able to access two lower cells? Let’s consider a brief example. Suppose cells 0, 1, and 2 contain our binary variables, and we begin with cell 3 as our first NAND cell operation. We introduce a conditional operator that enables us to effectively have the following form:

<div align="center">
(P->(C = A NAND B))
</div>

<br>

We can represent our implication operator as follows:

<div align="center">
(!P | (C = A NAND B))
</div>

<br>

We may rewrite our above two expressions using the CNF (conjunctive normal form) for the NAND operator:

<div align="center">
P->((!A | !B | C) & (A | C) & (B | C))
</div>

<br>

<div align="center">
(!P | ((!A | !B | C) & (A | C) & (B | C)))
</div>

<br>

We place the !P into each of the clauses:

<div align="center">
(!P | (!A | !B | !C)) & (!P | (A | C)) & (!P | (B | C))
</div>

<br>

Simplifying:

<div align="center">
(!P | !A | !B | !C) & (!P | A | C) & (!P | B | C)
</div>

<br>

The 3SAT solver requires all clauses to have exactly 3 variables, so we introduce a helper variable to break up the first clause which has 4 variables:

<div align="center">
(!P | !A | H) & (!H | !B | C) & (!P | A | C) & (!P | B | C)
</div>

<br>

Our plan was to compute cell C3. The conditional Px identifies which combination of two of C0, C1, and C2 is being used. We also want to force either zero or one unique combined pair of C0, C1, C2. We want the option of exactly one unique pair so there is no dubiety and we want the option of exactly zero unique pairs because having zero usage of the cell represents our NO-OP code (the overall size of a proof of a theorem is impossible to predict, so if the proof uses 1001 cells and you’ve arranged for there to be up to 8000 cells, the proof still is possible to generate and contain within our table). In order to achieve this, we say that usage of one precondition variable Px implies no lower Py is used like this: Px->!Py for all y lower than x. Following is our computation for that cell.

<br>
P0->(C3 = C0 NAND C0)
<br>
P1->(C3 = C0 NAND C1)
<br>
P2->(C3 = C0 NAND C2)
<br>
P3->(C3 = C1 NAND C1)
<br>
P4->(C3 = C1 NAND C2)
<br>
P5->(C3 = C2 NAND C2)
<br>
P1->!P0
<br>
P2->!P0
<br>
P2->!P1
<br>
P3->!P0
<br>
P3->!P1
<br>
P3->!P2
<br>
P4->!P0
<br>
P4->!P1
<br>
P4->!P2
<br>
P4->!P3
<br>
P5->!P0
<br>
P5->!P1
<br>
P5->!P2
<br>
P5->!P3
<br>
P5->!P4
<br>
<br>
And again, because each CNF clause must contain exactly three literals, we include the -1 value for false:

<br>
<br>

<div align="center">
(!Px | !Py | F) = (!Px | !Py | -1)
</div>

<br>

The generation of the 3CNF for a table of a given size can be parallelized because the majority of the table is composed of blank cells.

Within the very last cells of the table we express the goal state that is desired, and at the very beginning of the table is where we include any axioms described by NAND cells and binary variables and also a prompt. Such a prompt for mathematics may be e^(πi) - 1 = 0 or simply 0 = 0. From a mathematics standpoint, all computers are basically able to do is add. That’s it. However, computers can perform all mathematical operations. It turns out that subtraction is simply performing a two’s complement inversion on a number and adding it to the first number. Multiplication can be expressed as adding a column of numbers generated from ANDing the bits of two numbers with progressive bit shifts. And division is simply the multiplication of a known number by an unknown number and forcing the result to equal a desired product, with the equality achieved through XNOR operators. Raising something to a power can be expressed as multiplication, and taking the logarithm of a number is raising a known logarithmic base to an unknown power and forcing it to equal a desired result. Calculus reduces to these arithmetical operations. So between a chosen axiom set and prompt at the beginning and the desired goal state expressed at the end we have NAND cells that have not yet been populated with truth values, and the 3SAT solver efficiently either finds a satisfying assignment of truth values to these unassigned NAND cell variables or it reports that the instance is not satisfiable, meaning that for the given number of NAND cells between the prompt and the goal state (mathematical proof steps), a mathematical proof is not possible.



<h2 align="center">
Application to the Grand Unified Theory
</h2>

We wish to represent the field of chemistry using mathematics and the field of physics. To achieve this we present a new atomic model of the universe. We dismiss the entire Standard Model containing electronics, protons, neutrons, muons, photons, quarks, the Higgs-Boson, and the like. We also dismiss the entire field of quantum theory. In place of these spectacular failures to explain the subatomic world, we consider the stars in the sky to be atoms for some very large people, and the atoms in our world to be stars for some very small people. The Earth is a subatomic particle, as is every planet, asteroid, spec of dust, and anything else that has less mass than is necessary to sustain the “proton-proton” nuclear fusion reaction that occurs starting with star-level atoms of the hydrogen species (approximately 0.08 masses of our Sun). This subatomic matter that is on a smaller scale than our atom-level atoms is the identity of the mysterious dark matter, and is what electrical current and magnetic fields are made of. Because a star-level hydrogen atom is 0.08 solar masses, this means that our Sun is a carbon-12 atom, having approximately 12.5 times the mass of a star-level hydrogen atom. All of chemistry can be represented by the masses of the atoms. Just as the masses of the stars are not expressed as exact integer multiples of the mass of a star-level hydrogen atom, the masses of atom-level atoms also are not exact integer multiples of an atom-level hydrogen atom. And just as stars are both created from nebula matter coming together and destroyed at the end of their lives, atom-level atoms are also similarly both created and destroyed.

The fusion reaction requiring the second-smallest amount of energy to sustain is called the “deuterium-deuterium” reaction, and this occurs beginning with the mass of a star-level helium-4 atom. The reason Noble Gas atoms just about explode in size relative to the atomic species immediately preceding them is because once this new fusion reaction dominates at the core of the atom, the “deuterium-deuterium” reaction for helium (or the CNO cycle for neon) expels all the unreacted hydrogen fuel to the exterior of the core where it does not react and undergo the “proton-proton” reaction anymore. This thick layer of hydrogen fuel must be penetrated by another star in order for the cores of the two star-level atoms to establish a new effective mass at a new effective center of mass, which is why Noble Gas atoms tend to be rather non-reactive with other atoms. However, when two atoms do bond together, the bond is strongest when an effective Noble Gas mass at an effective new center of mass allows for the fusion reaction corresponding to that Noble Gas atomic mass to occur.

As was said above, dark matter is the identity of the material being exchanged in electrical and magnetic fields. An electrical current is the transportation of dark matter along a closed circuit and a magnetic field is the spinning and swirling forward motion of dark matter as it is moved through a conductor that is in the form of a repeating loop. The equation for gravitational force between particles of masses m1 and m2 is F = Gm1m2/r^2, and once again, dark matter is the identity of the gravitational field. All this subatomic matter- this dark matter- is being drawn into the center of the Earth, and it collides with the atoms that make up ourselves as humans and all other molecules and compounds, pinning us down on the surface of the planet. A ceramic or neodymium magnet obtains its magnetic field by being exposed to a magnetic field as it is being formed, which produces tiny grooves in a spinning/swirling progression forward, and the magnetic field is then later produced as the gravitational dark matter raining down on the Earth gets channeled through these grooves and starts itself to spin and swirl.

Now we have a model of chemistry that can be entirely expressed by numbers and mathematical operations.
