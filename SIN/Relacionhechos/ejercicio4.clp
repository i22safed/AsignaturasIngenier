(deftemplate familia
	(slot familiar1(type STRING))
	(slot familiar2(type STRING))
	(slot relacion(type STRING))
)

(deffacts hechos
	(familia(familiar1 "Toni") (familiar2 "Elena") (relacion "marido_mujer"))
	(familia(familiar1 "Toni") (familiar2 "Rafa") (relacion "padre_hijo"))
	(familia(familiar1 "Toni") (familiar2 "Saul") (relacion "padre_hijo"))
	(familia(familiar1 "Lourdes") (familiar2 "Rafa") (relacion "madre_hijo"))
	(familia(familiar1 "Lourdes") (familiar2 "Saul") (relacion "madre_hijo"))
	(familia(familiar1 "Rafa") (familiar2 "Toni") (relacion "hermanos"))
)
