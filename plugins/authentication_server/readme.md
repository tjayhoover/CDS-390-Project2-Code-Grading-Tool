To install/run this server on a linux machine:

* open a terminal and create a virtual environment:
  * ```python -m venv venv```
* Activate the virtual environment, either by clicking on the dialog in VSCode or manually in the terminal by typing:
  * ```. ./venv/bin/activate```
* update install tools:
  * ```pip install --upgrade pip setuptools wheel```
* install dependencies:
  * ```pip install -r requirements.txt```
* run the server:
  * ```python auth_service.py```
