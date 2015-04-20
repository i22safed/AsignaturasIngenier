(deftemplate libro
	(multislot autor (type STRING)
			(default ?NONE))
	(multislot titulo (type STRING)
			(default ?NONE))
	(multislot editorial (type STRING)
			     (default ?DERIVE))
	(multislot edicion(type NUMBER)
			(default 0))
	(multislot anyo (type INTEGER)
		        (default ?DERIVE))
)

(deffacts hechos
(libro (autor "Mira,J.Delgado A.E, Boticario J.G") (titulo "Aspectos basicos de la inteligencia artificail") (editorial "Sanz y Torres")(edicion) (anyo 1995))
(libro (autor "Galan, S. F. ;Boticario, J. G. ;Mira, J") (titulo "Problemas resueltos de inteligencia artificial") (editorial "Adisson-weley IberoAmericana")(edicion)(anyo 1998))
(libro (autor "Rich E. Knight, K") (titulo "Inteligencia Artificial") (editorial "McGraw-Hill") (edicion 2)(anyo 1994))
)
