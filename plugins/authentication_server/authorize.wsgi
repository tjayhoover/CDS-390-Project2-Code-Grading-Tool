#/usr/bin/env python

import sys
import site

site.addsitedir('/var/www/AuthorizationServer/.venv/lib/python3.10/site-packages')
sys.path.insert(0, '/var/www/AuthorizationServer')

from app import app as application
