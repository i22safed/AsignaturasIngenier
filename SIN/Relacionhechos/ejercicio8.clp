(deftemplate ingredientes
	(multislot pisto)
	(multislot tortilla)
	(multislot despensa)
	(multislot comprar)
)



(deffacts hechos
	(ingredientes(pisto pimientosVerdes pimientosRojos berenjenas calabacines cebollas tomateTriturado sal aceite))
	(ingredientes(tortilla huevos patatas cebollas sal aceite))
	(ingredientes(despensa pimientosVerdes pimientosRojos cebollas aceite)(comprar calabacines berenjenas tomateTriturado sal huevos patatas ))
	(compras)
	(ingredientes(despensa pimientosVerdes pimientosRojos cebollas aceite calabacines berenjenas tomateTriturado sal huevos patatas)(comprar todo comprado)))



)



(deffacts hechos2
	(cocinar)
	(ingredientes(despensa pimientosVerdes pimientosRojos aceite calabacines berenjenas sal huevos patatas)(comprar  tomateTriturado cebollas)))
)
