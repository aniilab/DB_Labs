using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace MovieBase
{
    public partial class Actor
    {
        public Actor()
        {
            ActorsInMovies = new HashSet<ActorsInMovie>();
        }

        public int Id { get; set; }

        [Display(Name = "Ім'я актора")]
        public string Name { get; set; } = null!;

        [Display(Name = "Кількість нагород")]
        public int AwardsNumber { get; set; }

        public virtual ICollection<ActorsInMovie> ActorsInMovies { get; set; }
    }
}
