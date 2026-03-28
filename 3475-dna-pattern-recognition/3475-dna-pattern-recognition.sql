select *,
case when dna_sequence like 'ATG%' then 1 else 0 end as has_start,
if(dna_sequence like '%TAA' or dna_sequence like '%TAG' or dna_sequence like '%TGA',1,0) as has_stop,
if(dna_sequence like '%ATAT%',1,0)as has_atat,
if(dna_sequence like '%GGG%',1,0)as has_ggg
from samples