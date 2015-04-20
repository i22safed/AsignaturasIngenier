(deftemplate coche
	(slot num_coches(type INTEGER)
			(default ?DERIVE))
	(slot modelo(type STRING))
	(slot cilindrada(type INTEGER)
			(default ?DERIVE))
	(slot combustible(type STRING)
			(allowed-strings "gasoil" "gasolina"))
	(multislot num_puertas(type INTEGER))
	(multislot color(type STRING))
	(multislot vendedor(type STRING)
			    (default ?DERIVE))
	(multislot fecha(type SYMBOL)
			(default ?DERIVE))
	(multislot cliente(type STRING))
)




(deffacts hechos
	(coche(num_coches 1)(modelo "clio")(cilindrada 1600)(combustible "gasolina")(num_puertas 3)(color "azul"))
	(coche(num_coches 1)(modelo "clio")(cilindrada 1800)(combustible "gasoil")(num_puertas 5)(color "blanco"))
	(coche(num_coches 1)(modelo "megane")(cilindrada 1800)(combustible "gasoil")(num_puertas 5)(color "dorado"))
	(coche(num_coches 2)(modelo "megane")(cilindrada 1600)(combustible "gasolina")(num_puertas 5)(color "gris"))
	(coche(num_coches 1)(modelo "laguna")(cilindrada 2000)(combustible "gasolina")(num_puertas 5)(color "negro"))
	(coche(num_coches 1)(modelo "megane")(fecha 10/10/2003)(vendedor "Juan Perez")(cliente "Esteban Losada"))
	(coche(num_coches 1)(modelo "laguna")(fecha 13/10/2003)(vendedor "Ana Ballester")(cliente "Juan Cano"))
	(Juan Perez vendio un mengane el 10/10/2003 al cliente Esteban Losada)
	(Ana Ballester vendio un laguna el 13/10/2003 al cliente Juan Cano)
)
