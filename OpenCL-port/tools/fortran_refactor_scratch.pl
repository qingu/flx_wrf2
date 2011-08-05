=info
How do we replace the args in a subroutine call?

- Find a subroutine call
- first check if we now about it by looking in a list of subroutine calls
- if we know it, it means we have resolved the globals, the list should be added to the node;
then just add the globals to the call
- otherwise, add the index in the list of source lines to a hash of subs 
- in fact, this can be a hash of "anythings", i.e. $nodes{$filename}{'subcall'}{$name}={'idxs'=>[$index,...],
	'globals'=>[],...};
- recurse and figure out globals used. also, store the signature in the node hash
- add the globals to the end of the signature, and emit the new code.
- it would be nice to emit the code in a hash $refactored_sources{$filename}=\@lines;
- return the list of all the globals to be added to the call
- update the call in %refactored_sources

This approach will work well until we need to insert new lines, because then we'd need to renumber %nodes
Which is not so hard:

simply loop over all pairs in the hash, and if the idx is greater than the new idx, increment it with the number of lines

=cut
my @src_lines=(1,2,5,6,7);
@src_lines=map {"$_\n"} @src_lines;
my @extra_lines=("3\n","4\n");

my $lref=insert_lines(\@extra_lines,\@src_lines,2);
for my $l (@{$lref}) {
	print $l;
}
for my $l (@src_lines) {
	print $l;
}

sub insert_lines {
	(my $lref, my $srcref,my $idx)=@_; # \@lines, \@src_lines, $idx;
	my $nsrc=[@{$srcref}];
	splice(@{$nsrc},$idx,0,@{$lref});
	return $nsrc;
}

=info2
We also need a convenience function to split long lines.
- count the number of characters, i.e. length()
- find the last comma before we exceed 64 characters (I guess it's really 72-5?):
=cut

my $line='We also need a convenience function to split long lines: count the number of characters, i.e. length(); find the last comma before we exceed 64 characters (I guess it is really 72-5?)';
sub split_long_line {	
	my $line=shift;
	my @chunks=@_;
	my $nchars=64;
	my $split_on=' ';
	my $ll= length($line);
	my $rline= join('',reverse(split('',$line)));
	my $idx= index($rline,$split_on,$ll-$nchars);
	push @chunks, substr($line,0,$ll-$idx,'');
	if (length($line)>$nchars) {
		&split_long_line ($line,@chunks);
	} else { 
		push @chunks, $line;
		return @chunks;
	}
}

my @chunks=split_long_line ($line);
		
for my $c (@chunks) {
print $c,"\n";
}