--
-- Create tables for cSQLiteOutputVectorManager.
--

DROP TABLE IF EXISTS vecdata;
DROP TABLE IF EXISTS vecattr;
DROP TABLE IF EXISTS vector;
DROP TABLE IF EXISTS vrun;

CREATE TABLE vrun (
	id INTEGER PRIMARY KEY,
	runnumber INTEGER NOT NULL,
	network VARCHAR(80) NOT NULL,
	date DATETIME DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE vector (
	id INTEGER PRIMARY KEY,
	runid INTEGER UNSIGNED NOT NULL,
	module VARCHAR(200) NOT NULL,
	name VARCHAR(80) NOT NULL,
	FOREIGN KEY (runid) REFERENCES vrun(id)
);

CREATE TABLE vecattr (
	vectorid INTEGER UNSIGNED NOT NULL,
	name VARCHAR(200) NOT NULL,
	value VARCHAR(200) NOT NULL,
	FOREIGN KEY (vectorid) REFERENCES vector(id)
);

CREATE TABLE vecdata (
	vectorid INTEGER UNSIGNED NOT NULL,
	time DOUBLE PRECISION NOT NULL,
	value DOUBLE PRECISION NOT NULL,
	FOREIGN KEY (vectorid) REFERENCES vector(id)
);