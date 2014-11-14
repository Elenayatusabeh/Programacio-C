/*1.	Mostrar el número, cognom i especialitat de cada doctor amb el nom de l'hospital en què treballa.*/
select d.doctor_no, d.cognom, d.especialitat, h.nom
from doctor d join hospital h on (d.hospital_cod=h.hospital_cod)

/*2.	Mostrar el codi (inscripció) de tots els malalts acompanyats del codi d'hospital i nom de
	l'hospital on es troben ingressats.*/
select m.inscripcio, h.hospital_cod, h.nom 
from (malalt m join ingressos i on (m.inscripcio=i.inscripcio))
               join hospital h on (i.hospital_cod=h.hospital_cod)
               
/*3.	Mostrar el cognom de tots els malalts que es troben actualment ingressats a l'hospital Provincial acompanyats del 
número de llit que se'ls ha assignat i el nom de la sala on són.*/
select m.cognom, i.llit, s.nom
from ((malalt m join ingressos i on (m.inscripcio=i.inscripcio))
                join hospital h on (i.hospital_cod=h.hospital_cod))
                join sala s on (s.sala_cod=i.sala_cod and h.hospital_cod=s.hospital_cod)
where upper(h.nom)like 'PROVINCIAL'

/*4.	Mostrar el codi i nom de cada hospital amb el codi i nom de cadascuna de les seves sales.*/
select h.hospital_cod, h.nom, s.sala_cod, s.nom
from hospital h join sala s on (h.hospital_cod=s.hospital_cod)

/*5.	De cada malalt que està ingressat actualment mostra el seu cognom amb el codi i nom de l'hospital i de la sala en què es troba.*/
select m.cognom, h.hospital_cod, h.nom, s.sala_cod, s.nom
from  ((malalt m join ingressos i on (m.inscripcio=i.inscripcio))
                 join hospital h on (i.hospital_cod=h.hospital_cod))
                 join sala s on (s.sala_cod=i.sala_cod and h.hospital_cod=s.hospital_cod)
where i.dt_dalta is not null

/*6.	Mostra el número, cognom i funció de cada empleat acompanyat del nom de l'hospital en el qual treballa.*/
select p.empleat_no, p.cognom, p.funcio, h.nom
from plantilla p join hospital h on (p.hospital_cod=h.hospital_cod)

/*7.	Mostra el número, cognom i funció de cada empleat acompanyat del codi i nom de l'hospital en què treballa i del codi 
i nom de la sala a la qual està assignat.*/
select p.empleat_no, p.cognom, p.funcio, h.hospital_cod ,h.nom, s.sala_cod, s.nom
from (plantilla p join hospital h on (p.hospital_cod=h.hospital_cod))
                  join sala s on (s.hospital_cod=p.hospital_cod and s.sala_cod=p.sala_cod)

/*8.	Mostra una llista dels homes que estan ingressats en cada hospital ordenats pel nom de l'hospital i dins de cada 
hospital pel cognom del malalt.*/
select h.nom, m.*
from (malalt m join ingressos i on (i.inscripcio=m.inscripcio))
               join hospital h on (i.hospital_cod=h.hospital_cod)
where upper(m.sexe) like 'H'
order by 1, m.cognom

/*9.	Mostra una llista dels treballadors assignats a cada sala en cada torn ordenats pels torns i dins de cada 
torn pel cognom dels treballadors.*/
select p.*
from plantilla p join sala s on (p.sala_cod=s.sala_cod and p.hospital_cod=s.hospital_cod)
order by p.torn, p.cognom

/*10.	Mostra la llista dels empleats de l'hospital Provincial ordenats pel seu salari (de major a menor salari).*/
select p.*
from  plantilla p join hospital h on (h.hospital_cod=p.hospital_cod)
where upper(h.nom) like 'PROVINCIAL'
order by p.salari desc