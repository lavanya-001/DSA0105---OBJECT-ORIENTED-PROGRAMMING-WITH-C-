# TASK 02 – FROM REQUIREMENT TO HIERARCHY

**Name:** Lavanya K.  
**Register Number:** 192565025  
**Compiler:** g++ 15.2.0

## Relationships
- Student is-a Person – Single inheritance.
- Staff is-a Person – Hierarchical inheritance.
- TeachingAssistant is-a Student and Staff – Multiple inheritance.
- ResearchScholar is-a Student – Multilevel inheritance.
- TeachingAssistant uses hybrid inheritance.

## Diamond Problem
When TeachingAssistant inherits from Student and Staff, both may contain separate Person objects. This creates ambiguity and duplicate data. Virtual inheritance ensures only one shared Person base object.

## Access Table

| Person member | Public inheritance | Protected inheritance | Private inheritance |
|---|---|---|---|
| Public | Public | Protected | Private |
| Protected | Protected | Protected | Private |
| Private | Not directly accessible | Not directly accessible | Not directly accessible |

## Result
Virtual base inheritance was implemented successfully. The TeachingAssistant object shares one Person base object. ResearchScholar inheritance was also demonstrated.
