(deftemplate animales
	(slot rango1(type STRING)
		      (allowed-strings "Mamiferos" "Reptiles" "Aves"))
	(slot rango2 (type STRING)
		     (allowed-strings "Roedores" "Felinos" "Serpientes" "Rapaces"))
	(multislot rango3 (type STRING)
		     (allowed-strings "Rata" "Ardilla" "Tigre" "Lince" "Jaguar" "Boa" "Cobra" "Diurnas" "Nocturnas"))
	(multislot rango4 (type STRING)
		     (default ?DERIVE)
		     (allowed-strings "Halcon" "Gavilan" "Buho" "Lechuza"))
)




(deffacts hechos
	(animales(rango1 "Mamiferos")(rango2 "Roedores")(rango3 "Rata" "Ardilla"))
	(animales(rango1 "Mamiferos")(rango2 "Felinos")(rango3 "Tigre" "Lince" "Jaguar"))
	(animales(rango1 "Reptiles")(rango2 "Serpientes")(rango3 "Boa" "Cobra"))
	(animales(rango1 "Aves")(rango2 "Rapaces")(rango3 "Diurnas")(rango4 "Halcon" "Gavilan"))
	(animales(rango1 "Aves")(rango2 "Rapaces")(rango3 "Nocturnas")(rango4 "Buho" "Lechuza"))
)
