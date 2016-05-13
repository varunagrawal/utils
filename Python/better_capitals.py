# Just use python's .title() method

def capitalize(s, sep=' ', joiner=None):
    if not joiner: joiner = sep

    t = joiner.join([(x[0].upper() + x[1:]) for x in (s.split(sep))])

    return t


print(capitalize('varun agrawal'))
print(capitalize('varun_agrawal', sep='_'))
print(capitalize('varun_agrawal', sep='_', joiner=' '))
